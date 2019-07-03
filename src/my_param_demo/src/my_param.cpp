#include <ros/ros.h>
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"my_param_demo");//
    ros::NodeHandle nh;
    int parameter1,parameter2,parameter3,parameter4,parameter5;

    //get param的三种方法
    //1	ros::param::get()获取参数“param1”的value,写入到parameter1上
	bool ifget1=ros::param::get("param1",parameter1);
	//2	ros::NodeHandle::getParam()获取参数,与1作用相同
	bool ifget2=nh.getParam("param2",parameter2);
	//3	ros::NodeHandle::param()类似于1和2
	//但如果get不到指定的param,它可以给param指定一个默认值(如33333)
	nh.param("param3",	parameter3,	33333);

	ROS_INFO("param1:%d\nparam2:%d\nparam3:%d",parameter1,parameter2,parameter3);

    //Set Param的两种方法
	//1	ros::param::set()设置参数
	parameter4=4;
	ros::param::set("param4",parameter4);
	//2	ros::NodeHandle::setParam()设置参数
	parameter5=5;
	nh.setParam("param5",parameter5);

    //Check	Param的两种方法
	//1	ros::NodeHandle::hasParam()
	bool ifparam5=nh.hasParam("param5");
	//2	ros::param::has()
	bool ifparam6=ros::param::has("param6");

    //Delete Param
	//1	ros::NodeHandle::deleteParam()
	bool ifdeleted5=nh.deleteParam("param5");
	//2	ros::param::del()
	bool ifdeleted6=ros::param::del("param6");
    
    return 0;
}
