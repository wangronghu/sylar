#ifndef __SYLAR_LOG_H__
#define __SYLAR_LOG_H__
#include<string>
#include<stdint.h>//用于int32位
#include<memory>//用于智能指针
namespace sylar{

//日志事件，用于将日志生成作为event；包含所有属性
class LogEvent{
public:
    typedef std::shared_ptr<LogEvent> ptr;//用智能指针管理内存
    LogEvent();
private:
    const char* m_file = nullptr;   //文件名
    int32_t m_line = 0;             //行数
    uint32_t m)elapse = 0;          //程序启动开始到现在的毫秒数
    uint32_t m_threadId = 0;        //线程id
    uint32_t m_fiberId  = 0;        //协程id
    uint64_t m_time = 0;            //时间戳
    std::string m_content:          //内容

}
//日志级别
class LogLevel{
    enum Level{
        DEBUG = 1;
        INFO = 2;
        WARN = 3;
        ERROR = 4;
        FATAL = 5;
    };
};
//日志输出---要有级别--要有输出地方，这里设为私有
class Logger { 
public:
    typedef std::shared_ptr<Logger> ptr;
    //一般要传入名字
	Logger(const std::string& name = "root"){
    };
    void log(LogLevel level, const LogEvent::ptr event);
private:
    std::string m_name;
    LogLevel::level m_level;
    LogAppender::ptr ;
};

//日志输出地--定义为虚基列表
class LogAppender {
public:
    typedef std::shared_ptr<LogAppender> ptr;
	virtual ~Appender();
    void log(LogLevel level, const LogEvent::ptr event);
private:
    LogLevel::Level m_level;
};
//日志格式
class LogFormatter{
public:
   typedef std::shared_ptr<LogFormatter> ptr;
   std::string format(LogEvent::ptr event);
private:
};
//输出到控制台的Appender
class StdoutLogAppender : public LogAppender{

};
class FileLogAppender : public LogAppender{

};
}
#endif

