#ifndef __DB_INTERFACE_HPP
#define __DB_INTERFACE_HPP
#include <mongo/client/dbclient.h>
#include <vector>
#include "acl/types.hpp"
#include "acl/user.hpp"
#include "acl/group.hpp"
namespace db 
{
  // initalize
  void Initalize(); // should only be called once by initial thread
  
  // user functions
  acl::UserID GetNewUserID();
  void SaveUser(const acl::User& user);    
  void GetUsers(std::vector<acl::User*>& users);

  // group functions
  acl::GroupID GetNewGroupID();
  void SaveGroup(const acl::Group& group);
  void GetGroups(std::vector<acl::Group*>& groups);


// end
}
#endif