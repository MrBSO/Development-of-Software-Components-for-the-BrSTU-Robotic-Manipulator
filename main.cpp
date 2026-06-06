#include <rclcpp/rclcpp.hpp>
#include "panda_qt_gui/MainWindow.hpp"
int main(int argc, char *argv[])
{ 
    rclcpp::init(argc, argv);
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    int result = app.exec();
    rclcpp::shutdown();
    return result;
}
