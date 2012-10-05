#ifndef __CFG_CONFIG_CPP
#define __CFG_CONFIG_CPP
#include <vector>
#include <string>
#include <boost/unordered_map.hpp>
#include <tr1/memory>
#include <tr1/unordered_map>
#include "cfg/exception.hpp"
#include "cfg/setting.hpp"
#include "cfg/factory.hpp"
#include "fs/path.hpp"

namespace cfg
{

class Config
{ 
  static int latestVersion;
  int version;

  std::string config;
  Factory factory;
 
  void Parse(const std::string& line);
  
  bool CheckSetting(const std::string& name);
  void SanityCheck();

  std::tr1::unordered_map<std::string, int> settingsCache;

  // containers
  setting::Path sitepath;
  setting::Path tlsCertificate;
  // glftpd
  setting::AsciiDownloads asciiDownloads;
  setting::ACL shutdown;
  int freeSpace;
  std::vector<setting::UseDirSize> useDirSize;
  setting::Timezone timezone;
  setting::Bool colorMode;
  std::string sitenameLong;
  std::string sitenameShort;
  std::string loginPrompt;
  setting::Path rootpath;
  setting::Path reloadConfig;
  std::vector<std::string> master;
  std::vector<setting::SecureIp> secureIp;
  std::vector<setting::SecurePass> securePass;
  setting::Path datapath;
  setting::Path pwdPath;
  setting::Path grpPath;
  setting::Path botscriptPath;
  std::vector<std::string> bouncerIp;
  std::vector<setting::SpeedLimit> speedLimit;
  std::vector<setting::SimXfers> simXfers;
  std::vector<std::string> calcCrc;
  std::vector<std::string> xdupe;
  int mmapAmount;
  int dlSendfile;
  int ulBufferedForce;
  setting::Path minHomedir;
  std::vector<std::string> validIp;
  std::vector<std::string> activeAddr;
  std::vector<std::string> pasvAddr;
  setting::Ports activePorts;
  setting::Ports pasvPorts;
  setting::AllowFxp allowFxp;
  std::vector<setting::Path> welcomeMsg;
  std::vector<setting::Path> goodbyeMsg;
  std::vector<setting::Path> newsfile;
  setting::Path banner;
  std::vector<setting::Alias> alias;
  std::vector<setting::Path> cdpath;
  std::vector<std::string> ignoreType;
  // ind rights
  std::vector<setting::Right> delete_; // delete is reserved
  std::vector<setting::Right> deleteown;
  std::vector<setting::Right> overwrite;
  std::vector<setting::Right> resume;
  std::vector<setting::Right> rename;
  std::vector<setting::Right> renameown;
  std::vector<setting::Right> filemove;
  std::vector<setting::Right> makedir;
  std::vector<setting::Right> upload;
  std::vector<setting::Right> download;
  std::vector<setting::Right> nuke;
  std::vector<setting::Right> dirlog;
  std::vector<setting::Right> hideinwho;
  std::vector<setting::Right> freefile;
  std::vector<setting::Right> nostats;
  // end rights
  std::vector<setting::StatSection> statSection;
  std::vector<setting::PathFilter> pathFilter;
  std::vector<setting::MaxUsers> maxUsers;
  setting::ACLInt maxUstats;
  setting::ACLInt maxGstats;
  std::vector<std::string> bannedUsers;
  std::vector<setting::Right> showDiz;
  std::vector<setting::ShowTotals> showTotals;
  setting::Bool dlIncomplete;
  setting::Bool fileDlCount;
  setting::DupeCheck dupeCheck;
  std::vector<setting::Script> script;
  std::vector<std::string> idleCommands;
  int totalUsers;
  setting::Lslong lslong;
  std::vector<setting::HiddenFiles> hiddenFiles;
  std::vector<std::string> noretrieve;
  std::vector<std::string> tagline;
  std::string email;
  int multiplierMax;
  int oneliners;
  setting::Requests requests;
  setting::Lastonline lastonline;
  int emptyNuke;
  std::vector<setting::Path> nodupecheck;
  std::vector<setting::Creditcheck> creditcheck;
  std::vector<setting::Creditloss> creditloss;
  setting::NukedirStyle nukedirStyle;
  setting::ACL hideuser;
  std::vector<setting::Privgroup> privgroup;
  std::vector<setting::Msgpath> msgpath;
  std::vector<setting::Privpath> privpath;
  std::vector<setting::SiteCmd> siteCmd;
  int maxSitecmdLines;
  std::vector<setting::Cscript> cscript;

public:
  Config(const std::string& configFile);
  ~Config() {};  

  int Version() const { return version; };

  // getters
  const setting::Path& Sitepath() const { return sitepath; };
  const setting::Path& TlsCertificate() const { return tlsCertificate; };
  // glftpd
  const setting::AsciiDownloads& AsciiDownloads() const { return asciiDownloads; }; 
  const setting::ACL& Shutdown() const { return shutdown; };
  const int FreeSpace() const { return freeSpace; };
  const std::vector<setting::UseDirSize>& UseDirSize() const { return useDirSize; };
  const setting::Timezone& Timezone() const { return timezone; };
  const bool ColorMode() const { return colorMode; };
  const std::string& SitenameLong() const { return sitenameLong; };
  const std::string& SitenameShort() const { return sitenameShortg; };
  const std::string& LoginPrompt() const { return loginPrompt; };
  const setting::Path& Rootpath() const { return rootpath; };
  const setting::Path& ReloadConfig() const { return reloadconfig; };
  const std::vector<std::string>& Master() const { return master; };  
  const std::vector<setting::SecureIp>& SecureIp() const { return secureIp; };
  const std::vector<setting::SecurePass>& SecurePass() const { return securePass; };
  const setting::Path& Datapath() const { return datapath; };
  const setting::Path& PwdPath() const { return pwdPath; };
  const setting::Path& GrpPath() const { return grpPath; };
  const setting::Path& BotscriptPath() const { return botscriptPath; };
  const std::vector<std::string>& BouncerIp() const { return BouncerIp; };
  const std::vector<setting::SpeedLimit>& SpeedLimit() const { return speedLimit; };
  const std::vector<setting::SimXfers>& SimXfers() const { return simXfers; };
  const std::vector<std::string>& CalcCrc() const { return calcCrc; };
  const std::vector<std::string>& Xdupe() const { return xdupe; };
  const int MmapAmount() const { return mmapAmount; };
  const int DlSendFile() const { return dlSendFile; };
  const int UlBufferedForce() const { return ulBufferedForce; };
  const setting::Path& MinHomedir() const { return minHomedir; };
  const std::vector<std::string>& ValidIp() const { return validIp; };
  const std::vector<std::string>& ActiveAddr() const { return activeAddr; };
  const std::vector<std::string>& PasvAddr() const { return pasvAddr; };
  const setting::Ports& ActivePorts() const { return activePorts; };
  const setting::Ports& PasvPorts() const { return pasvPorts; };
  const setting::AllowFxp& AllowFxp() const { return allowFxp; };
  const std::vector<setting::Path>& WelcomeMsg() const { return welcomeMsg; };
  const std::vector<setting::Path>& GoodbyeMsg() const { return goodbyeMsg; };
  const std::vector<setting::Path>& Newsfile() const { return newsfile; };
  const setting::Path& Banner() const { return banner; };
  const std::vector<setting::Alias>& Alias() const { return alias; };
  const std::vector<setting::Path>& Cdpath() const { return cdpath; };
  const std::vector<std::string>& IgnoreType() const { return ignoreType; };

  // rights section
  const std::vector<setting::Right>& Delete() const { return delete_; }; 
  const std::vector<setting::Right>& Deleteown() const { return deleteown; }; 
  const std::vector<setting::Right>& Overwrite() const { return overwrite; }; 
  const std::vector<setting::Right>& Resume() const { return resume; }; 
  const std::vector<setting::Right>& Rename() const { return rename; }; 
  const std::vector<setting::Right>& Renameown() const { return renameown; }; 
  const std::vector<setting::Right>& Filemove() const { return filemove; }; 
  const std::vector<setting::Right>& Makedir() const { return makedir; }; 
  const std::vector<setting::Right>& Upload() const { return upload; }; 
  const std::vector<setting::Right>& Download() const { return download; }; 
  const std::vector<setting::Right>& Nuke() const { return nuke; }; 
  const std::vector<setting::Right>& Dirlog() const { return dirlog; }; 
  const std::vector<setting::Right>& Hideinwho() const { return hideinwho; }; 
  const std::vector<setting::Right>& Freefile() const { return freefile; }; 
  const std::vector<setting::Right>& Nostats() const { return nostats; }; 

  const std::vector<setting::StatSection>& StatSection() const { return statSection; };
  const std::vector<setting::PathFilter>& PathFilter() const { return pathFilter; };
  const std::vector<setting::MaxUsers>& MaxUsers() const { return maxUsers; };
  const setting::ACLint MaxUstats() const { return maxUstats; };
  const setting::ACLint MacGstats() const { return maxGstats; };
  const std::vector<std::string>& BannedUsers() const { return bannedUsers; };
  const std::vector<setting::Right>& ShowDiz() const { return showDiz; };
  const bool DlIncomplete() const { return dlIncomplete; };
  const bool FileDlCount() const { return fileDlCount; };
  const setting::DupeCheck& DupeCheck() const { return dupeCheck; };
  const std::vector<setting::Script>& Script() Const { return script; };
  const std::vector<std::string>& IdleCommands() const { return idleCommands; };
  const int TotalUsers() const { return totalUsers; };
  const setting::Lslong& Lslong() const { return lslong; };
  const std::vector<setting::HiddenFiles>& HiddenFiles() const { return hiddenFiles; };
  const std::vector<std::string>& Noretrieve() const { return noretrieve; };
  const std::vector<std::string>& Tagline() const { return tagline; };
  const std::string& Email() const { return email; }:
  const int MultiplierMax() const { return multiplierMax; };
  const int Oneliners() const { return oneliners; };
  const setting::Requests& Requests() const { return requests; };
  const setting::Lastonline& Lastonline() const { return lastonline; };
  const int EmptyNuke() const { return emptyNuke; };
  const std::vector<setting::Path>& Nodupecheck() const { return nodupecheck; };
  const std::vector<setting::Creditcheck>& Creditcheck() const { return creditcheck; };
  const std::vector<setting::Creditloss>& Creditloss() const { return creditloss; };
  const setting::NukedirStyle& NukedirStyle() const { return nukedirStyle; };
  const setting::ACL& Hideuser() const { return hideuser; };
  const std::vector<setting::Privgroup>& Privgroup() const { return privgroup; };
  const std::vector<setting::Msgpath>& Msgpath() const { return msgpath; };
  const std::vector<setting::Privpath>& Privpath() const { return privpath; };
  const std::vector<setting::SiteCmd>& SiteCmd() const { return siteCmd; };
  const int MaxSitecmdLines() const { return maxSitecmdLines; };
  const std::vector<setting::Cscript>& Cscript() const { return cscript; };
  
};

typedef std::tr1::shared_ptr<cfg::Config> ConfigPtr;

}


#endif 
