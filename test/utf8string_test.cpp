#include <cstring>

#include <map>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <iostream>
#include <functional>

#include "common.hpp"

#include "../src/utf8string.cpp"


TEST_CLASS(Utf8String)

    TEST_METHOD(contructor)
        assert(Utf8String("红帽蓝图旗下转").raw() == "红帽蓝图旗下转");
        assert(Utf8String("白猫符绿水").size() == 5);
        assert(Utf8String("日照香炉绳子炎").substr(1, 4) == "照香炉绳");
    TEST_METHOD_END()


    TEST_METHOD(operators)
        assert(Utf8String("你微微一笑")[0] == '你');

        auto u8s = Utf8String("对我无言");
        u8s = Utf8String("我感觉为此我已经等待良久");

        assert(u8s[u8s.size() - 1] == '久');

        u8s = "罗钥轩天下No.1可爱！！！";
        assert(u8s.substr(0, 3) == "罗钥轩");

        u8s[3] = '宇';
        u8s[4] = '宙';
        assert(u8s == "罗钥轩宇宙No.1可爱！！！");

        u8s += "真的超级可爱啊啊啊啊！！！";
        assert(u8s == "罗钥轩宇宙No.1可爱！！！真的超级可爱啊啊啊啊！！！");

        Utf8String an8s = "真的超级可爱啊啊啊啊！！！";
        assert("罗钥轩宇宙No.1可爱！！！" + an8s == u8s);

        an8s = '我';
        assert(an8s == '我');
        assert(an8s.substr(0, 1) == '我');
    TEST_METHOD_END()


    TEST_METHOD(eq_and_neq)
        assert(Utf8String("我是一朵花") == "我是一朵花");
        assert(Utf8String("人类是一个新生儿") != Utf8String("他的力量是生长的力量"));
        assert(Utf8String("我爱你").substr(2) == "你");
    TEST_METHOD_END()


    TEST_METHOD(as_key_in_map)
        std::map<Utf8String, int> mps;
        std::vector<Utf8String> u8ss =
        {
            "夏天迷失的鸟群来到我窗前歌唱然后飞走",
            "秋天枯黄的叶子，无歌，一声叹息，在此飘落",
            "哦，世上小小的流浪者的队伍，请把你们的足迹留在我的文字里",
            "世界摘下巨大的面具面对它的爱人",
            "它变小如一首歌，如一次永恒的吻"
        };

        for (auto& u8str : u8ss) mps[u8str] = u8str.size();

        assert(mps["世界摘下巨大的面具面对它的爱人"] == 15);
    TEST_METHOD_END()

TEST_CLASS_END()