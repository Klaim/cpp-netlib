// Copyright 2012 Rob J Meijer. 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//This file in not a test, its a demo of how the use of network::utils::log_base is supposed to work.
//
//In order to not colide with Klaims work, yet to comunicate how stuff could work I put this code here
//derived from an earlier proposal on the mailinglist. If you want to compile this test, I suggest
//using the command line for now as such:
//
//        clang++ logger_demo.cpp ../src/utils/log_base.cpp -I../../../include/ -DNETWORK_ENABLE_LOGGING -o logger_demo
//
//If we don't need fine controll, it may be best to couple INNER_LOOP_DEBUG to NETWORK_ENABLE_LOGGING directly.
#ifdef NETWORK_ENABLE_LOGGING
#define INNER_LOOP_DEBUG
#endif

#include <network/utils/log_base.hpp>
#include <network/utils/inner_loop_log.hpp>


//This is an example of a class that needt to log.
class Foo: public network::utils::log_base { //Define LoggingClass as a baseclass.
     std::string const mName;
  public:
     Foo(std::string name):mName(name){}
     //An additional constructor for constructor based dependency injection.
     //Note that there should eventually only be the need for one constructor, which one depends on
     //if dependency injection is chosen as the model to use.
     Foo(std::string name,std::ostream &logstream):network::utils::log_base(logstream),mName(name){}
     //A method that does actual logging.
     void hi() {
        //Normal non perfoemance critical logging.
        log() << mName << " sends his greetings" << std::endl;
        for (int x=0;x<12;x++) {
           //Performance critical inner loop logging, only logs if compiled with -DINNER_LOOP_DEBUG
           INNER_LOOP_LOG("processing something");
        }
     }
};

int main(int argc,char **argv) {
    //The first scenario is the default of never logging unless explicitly specified.
    //Harry will use the null logger given that no stream is given and the static is not initiated. 
    Foo harry("Harry");
    //
    //In the second scenario we initialize the logging program wide using a static method.
#ifdef NETWORK_ENABLE_LOGGING
    network::utils::log_base::initializeDefaultLogStream(std::cout);
#endif
    //Now we create a Ted that should use the new default.
    Foo ted("Ted");
    //
    //In a third scenario, we have more fine controll and use a cleaner dependency injection form.
#ifdef NETWORK_ENABLE_LOGGING
    std::ostream &logstream=std::cerr;
#else
    network::utils::nullstreambuf<char> nullbuf;
    std::basic_ostream<char> logstream(&nullbuf);
#endif
    //Use of constructor based dependency injection for Bill.
    Foo bill("Bill",logstream);
    //
    //
    //Harry's logs are discarded by the null logger.
    harry.hi();
    //Ted logs to stdout.
    ted.hi();
    //Bills logs go to cerr.
    bill.hi();
}
