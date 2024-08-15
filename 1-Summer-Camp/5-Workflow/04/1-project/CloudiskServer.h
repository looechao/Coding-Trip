#ifndef __WD_CloudiskServer_HPP__ 
#define __WD_CloudiskServer_HPP__ 

#include <workflow/WFFacilities.h>
#include <wfrest/HttpServer.h>

class CloudiskServer
{
public:
    CloudiskServer(int cnt) 
    : _waitGroup(cnt)
    {}
    ~CloudiskServer() {}
    void start(unsigned short port);
    void loadModules();
private:
    //模块化的思维方式写代码
    void loadStaticResourceModule();
    void loadUserRegisterModule();
    void loadUserLoginModule();
    void loadUserInfoModule();
    void loadFileQueryModule();
    void loadFileUploadModule();
    void loadFileDownloadModule();

      // 处理函数
    void handle_user_register(const wfrest::HttpReq *req, wfrest::HttpResp *resp, SeriesWork *series);
    void handle_user_signin(const wfrest::HttpReq *req, wfrest::HttpResp *resp, SeriesWork *series);
    void handle_user_userinfo(const wfrest::HttpReq *req, wfrest::HttpResp *resp, SeriesWork *series);
    void handle_user_filequery(const wfrest::HttpReq *req, wfrest::HttpResp *resp, SeriesWork *series);
    void handle_user_fileupload(const wfrest::HttpReq *req, wfrest::HttpResp *resp, SeriesWork *series);

private:
    WFFacilities::WaitGroup _waitGroup;
    wfrest::HttpServer _httpserver;
};

#endif

