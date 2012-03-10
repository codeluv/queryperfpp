// Copyright (C) 2012  JINMEI Tatuya
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

#ifndef __QUERYPERF_DISPATCHER_H
#define __QUERYPERF_DISPATCHER_H 1

#include <libqueryperfpp_fwd.h>

#include <boost/noncopyable.hpp>

#include <sys/types.h>

namespace Queryperf {

class Dispatcher : private boost::noncopyable {
public:
    // Default parameters: derived from the original queryperf.
    //
    // Window size: maximum number of queries outstanding.
    static const size_t DEFAULT_WINDOW = 20;

    // parameters eventually taken:
    //   window size, test duration, server adress, server port
    //   socket buffer size
    ///
    /// \param msg_mgr A message manager object that handles I/O and timeout
    /// events.
    Dispatcher(MessageManager& msg_mgr, QueryContextCreator& ctx_creator);
    ~Dispatcher();

    void run();

private:
    struct DispatcherImpl;
    DispatcherImpl* impl_;
};

} // end of QueryPerf

#endif // __QUERYPERF_DISPATCHER_H 

// Local Variables:
// mode: c++
// End: