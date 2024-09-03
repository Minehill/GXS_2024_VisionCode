#include <rclcpp/rclcpp.hpp>
#include <qrmsg/srv/qr.hpp>
#include <opencv2/opencv.hpp>

class SearchResponse : public rclcpp::Node 
{
    public:
    SearchResponse(std::string name) : Node(name) 
    {
        RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
        // 创建服务
        // std::placeholders::_1, std::placeholders::_2为占位符，表示绑定函数的两个参数（请求、响应）
        search_block_server_ =
        this->create_service<qrmsg::srv::Qr>(
            "QrCallSearch",
            std::bind(&SearchResponse::handle_searchblock, this,
                    std::placeholders::_1, std::placeholders::_2));
    }

    private:
    // 收到请求的处理函数
    void handle_searchblock
    (
        const std::shared_ptr<qrmsg::srv::Qr::Request> request,
        std::shared_ptr<qrmsg::srv::Qr::Response> response) 
        {
            RCLCPP_INFO(this->get_logger(), "收到num: %ld way: %ld", request->num,request->way);
            response->finish = true;
            response->way = request->way;
            
        }
    // 声明服务
    rclcpp::Service<qrmsg::srv::Qr>::SharedPtr search_block_server_;
};


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SearchResponse>("BlockSearch"));
    rclcpp::shutdown();
    return 0;
}