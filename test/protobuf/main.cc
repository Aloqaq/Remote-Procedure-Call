#include"test.pb.h"
#include <iostream>
#include <string>
using namespace fixbug;//使用protoc的命名空间

int main()
{
    // LoginResponse rsp;
    // ResultCode *rc=rsp.mutable_result();
    // rc->set_errcode(0);
    // rc->set_errmsg("登录处理失败！");
    

    GetFriendListResponse rsp;
    ResultCode *rc=rsp.mutable_result();
    rc->set_errcode(0);

    User *user1=rsp.add_friend_list();
    user1->set_name("Tom");
    user1->set_age(24);
    user1->set_sex(User::Man);

    User *user2=rsp.add_friend_list();
    user2->set_name("Jerry");
    user2->set_age(20);
    user2->set_sex(User::Woman);

    std::cout<<rsp.friend_list_size()<<std::endl;

    return 0;
}

int main1()
{
    //封装login请求对象的数据
    LoginRequest req;
    req.set_name("zhangsan");
    req.set_pwd("123456");

    //对象数据的序列化-->char*
    std::string send_str;//序列化后的目标字符串
    if(req.SerializeToString(&send_str))
    {
        std::cout<<send_str.c_str()<<std::endl;
    }

    //从send_str反序列化一个login请求对象
    LoginRequest reqB;
    if(reqB.ParseFromString(send_str))
    {
        std::cout<<reqB.name()<<std::endl;
        std::cout<<reqB.pwd()<<std::endl;
    }
    return 0;
}