#pragma once
#include <spdlog/sinks/base_sink.h>

template <typename Mutex> class ringbuffer_sink : public spdlog::sinks::base_sink<Mutex> {
    public:
        void clear( ) { messages.clear( ); }

        std::deque<std::string> get_messages( ) { return messages; }

    private:
        std::deque<std::string> messages;

    protected:
        void sink_it_( const spdlog::details::log_msg& msg ) override {
            spdlog::memory_buf_t formatted;
            spdlog::sinks::base_sink<Mutex>::formatter_->format( msg, formatted );

            if ( messages.size( ) >= 500 ) messages.pop_front( );
            messages.emplace_back( formatted.data( ), formatted.size( ) );
        }
        void flush_( ) override {}
};

using ringbuffer_sink_mt = ringbuffer_sink<std::mutex>;
