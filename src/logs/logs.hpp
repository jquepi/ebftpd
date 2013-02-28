#ifndef __LOGS_LOGS_HPP
#define __LOGS_LOGS_HPP

#include <string>
#include <sstream>
#include <iomanip>
#include "logs/logger.hpp"
#include "util/format.hpp"
#include "util/string.hpp"

namespace logs
{

void Initialise(const std::string& logsPath);

/*
 * log types:
 *
 * events   - for user events, mkdir, rmdir, login, logout 
 * security - bad password, connect from unknown host and other access / security errors
 * siteop   - user and group management events, other siteop tasks / changes
 * error    - any kind of exceptional failure, config parse error, etc
 * db       - any database related event or failure
 * debug    - miscellaneous debugging output
 */

struct Format : public util::Format
{
  Format& operator=(Format&&) = delete;
  Format& operator=(const Format&) = delete;
  Format(Format&&) = delete;
  Format(const Format&) = delete;
  
  Format(const util::Format::OutputFunction& output) :
    util::Format(output)
  { }
};

inline void Siteop(const std::string& admin, const std::string& message)
{
  extern Logger siteop;
  siteop.PushEntry("admin", Quote('\''), admin, "message",  message);
}

template <typename... Args>
void Siteop(const std::string& admin, const std::string& format, const Args&... args)
{
  extern Logger siteop;
  siteop.PushEntry("admin", Quote('\''), admin, "message", util::Format()(format, args...));
}

template <typename... Args>
void Event(const std::string& what, const Args&... args)
{
  extern Logger events;
  events.PushEntry("event", Tag(), util::ToUpperCopy(what), QuoteOn(), args...);
}

inline void Security(const std::string& what, const std::string& message)
{
  extern Logger security;
  std::ostringstream os;
  os << util::ToUpperCopy(what) << ": " << message;
  security.PushEntry("message", os.str());
}

template <typename... Args>
void Security(const std::string& what, const std::string& format, const Args&... args)
{
  extern Logger security;
  std::ostringstream os;
  os << util::ToUpperCopy(what) << ": " << format;
  security.PushEntry("message", util::Format()(os.str(), args...).String());
}

inline void Debug(const std::string& message)
{
  extern Logger debug;
  debug.PushEntry("message", message);
}

template <typename... Args>
void Debug(const std::string& format, const Args&... args)
{
  extern Logger debug;
  debug.PushEntry("message", util::Format()(format, args...).String());
}

inline void Database(const std::string& message)
{
  extern Logger db;
  db.PushEntry("message", message);
}

template <typename... Args>
void Database(const std::string& format, const Args&... args)
{
  extern Logger db;
  db.PushEntry("message", util::Format()(format, args...).String());
}

inline void Error(const std::string& message)
{
  extern Logger error;
  error.PushEntry("message", message);
}

template <typename... Args>
void Error(const std::string& format, const Args&... args)
{
  extern Logger error;
  error.PushEntry("message", util::Format()(format, args...).String());
}

inline void Transfer(const std::string& path, const std::string& direction, 
      const std::string& username, const std::string& groupname, 
      double startTime, long long kBytes, double xfertime, 
      bool okay, const std::string& section)
{
  extern Logger transfer;
  transfer.PushEntry(QuoteOn(), "epoch start", startTime, "direction", direction,
                     "username", username, "groupname", groupname,
                     "size", kBytes, "seconds", xfertime, "okay", okay ? "okay" : "fail",
                     "section", section, "path", path);
}

void InitialisePreConfig();
bool InitialisePostConfig();

}

#endif
