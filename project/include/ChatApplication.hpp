#ifndef PROJECT_INCLUDE_CHATAPPLICATION_HPP_
#define PROJECT_INCLUDE_CHATAPPLICATION_HPP_


#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <Wt/WServer.h>
#include <Wt/WTimer.h>

#include "ChatServer.hpp"
#include "ChatWidget.hpp"


class ChatApplication : public Wt::WApplication {
public:
    ChatApplication(const Wt::WEnvironment& env, ChatServer& server);

private:
    ChatServer&                 server_;
    const Wt::WEnvironment&     env_;
    std::unique_ptr<Wt::WTimer> timer_;
};


std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env, ChatServer& server) {
    return std::make_unique<ChatApplication>(env, server);
}

#endif  // PROJECT_INCLUDE_CHATAPPLICATION_HPP_