#include "scene.h"

Scene::Scene() {
    is_running = false;
}

bool Scene::Initialize() {
    // Initialise GLFW.
    if(!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW.\n");
        return false;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context.
    window_ = glfwCreateWindow(1024, 768, "Graphics Practice", NULL, NULL);
    if(window_ == NULL){
        fprintf(stderr, "Failed to open GLFW window.\n" );
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window_);

    // Initialize GLEW.
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW.\n");
        return false;
    }

    // Ensure we can capture the escape key to exit.
    glfwSetInputMode(window_, GLFW_STICKY_KEYS, GL_TRUE);

    camera = Camera(60.0f, 4.0f / 3.0f, 0.1f, 100.0f,
                    glm::vec3(0,0,5), glm::vec3(0,0,0), glm::vec3(0,1,0));

    light = { glm::vec3(0,3,0), glm::vec3(0,0,1), 5 };

    last_time_ = glfwGetTime();

    is_running = true;

    return true;
}

void Scene::Cleanup() {
    for (int i = 0; i < scene_objects_.size(); ++i) {
        scene_objects_[i]->Cleanup();
    }

    // Close OpenGL window and terminate GLFW
    glfwTerminate();
}

void Scene::AddObject(SceneObject* scene_object) {
    scene_objects_.push_back(std::unique_ptr<SceneObject>(scene_object));
    scene_object->scene = this;
}

void Scene::Update() {
    double current_time = glfwGetTime();
    float delta_time = float(current_time - last_time_);
    last_time_ = current_time;

    for (int i = 0; i < scene_objects_.size(); ++i) {
        scene_objects_[i]->Update(delta_time);
    }

    // Check if the ESC key was pressed or the window was closed
    is_running = (glfwGetKey(window_, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
                  glfwWindowShouldClose(window_) == 0);
}

void Scene::Render() {
    // Clear the screen.
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    for (int i = 0; i < scene_objects_.size(); ++i) {
        scene_objects_[i]->Render();
    }

    // Swap buffers
    glfwSwapBuffers(window_);
    glfwPollEvents();
}
