#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MyAPublisher : public rclcpp::Node
{
  public:
    MyAPublisher()
    : Node("myA_publisher"), count_(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::String>("my_a", 10);
      timer_ = this->create_wall_timer(
      1s, std::bind(&MyAPublisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = "Hy 51, hows life?" + std::to_string(count_++);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MyAPublisher>());
  rclcpp::shutdown();
  return 0;
}

