#include <iostream>
#include <thread>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <GLFW/glfw3.h>

using websocketpp::connection_hdl;
typedef websocketpp::server<websocketpp::config::asio> server;

class VectorscopeApp {
public:
    VectorscopeApp() {
        ws_server.init_asio();
        ws_server.set_message_handler([
            this](connection_hdl hdl, server::message_ptr msg) {
            // Echo received messages back to client
            ws_server.send(hdl, msg->get_payload(), msg->get_opcode());
        });
    }

    void run() {
        ws_server.listen(9002);
        ws_server.start_accept();
        std::thread ws_thread([this]() { ws_server.run(); });

        if (!glfwInit()) {
            std::cerr << "Failed to init GLFW" << std::endl;
            return;
        }
        GLFWwindow* window = glfwCreateWindow(800, 600, "Vectorscope", nullptr, nullptr);
        if (!window) {
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(window);
        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT);
            // TODO: render vectorscope
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwDestroyWindow(window);
        glfwTerminate();

        ws_server.stop();
        ws_thread.join();
    }

private:
    server ws_server;
};

int main() {
    VectorscopeApp app;
    app.run();
    return 0;
}
