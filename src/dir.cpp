#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/filesystem.hpp>
#include <boost/function.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <algorithm>
#include <openssl/md5.h>
#include <fstream>



using namespace std;
typedef boost::function<void(int, string)> NotifyFun;
namespace fs = boost::filesystem;
static int next_id = 0;
class Verify{
    vector<string> md5s;
public:
    bool verify(string filename){
	ifstream is(filename.c_str());
	string data((istreambuf_iterator<char>(is)), istreambuf_iterator<char>());

	string md5 = (char*)MD5(reinterpret_cast<const unsigned char*>(data.c_str()),
			  data.length(), NULL);

	if(find(md5s.begin(), md5s.end(), md5) != md5s.end()){
	    return false;
	} else {
	    md5s.push_back(md5);
	    return true;
	}
    }
};
Verify verify;

int init_dir(string dir, boost::function<void(string)> fun)
{
  int number = 0;
  for(fs::directory_iterator itr(dir); 
      itr!=fs::directory_iterator(); ++itr){
      try {
	  int id = boost::lexical_cast<int>(fs::basename(itr->path()));
	  if(verify.verify(itr->path().string()))
	    fun(itr->path().string());
	  else
	    remove(itr->path());
	  if(id>number)
	    number=id;
      } catch (...) {
      }
  }
  return number;
}
void monitor(string dir, NotifyFun fun)
{
  int number=1;
  fs::path path(dir);

  if(fs::is_directory(path)){
      for(fs::directory_iterator itr(path); 
	  itr!=fs::directory_iterator(); ++itr){
	  int n=0;
	  try {
	      n = boost::lexical_cast<int>(fs::basename(itr->path()));
	      if(n>=number)
		number = n+1;
	  } catch (...) {
	      std::cout << fs::basename(itr->path()) << " catch\n";
	  }
      }
  } else {
      throw "not an dir";
  }

  boost::asio::io_service io;
  boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));

  fs::path noname(path);
  noname/= "noname.doc";

  for(;;){
      t.wait();
      if(fs::exists(noname)){
	  if(verify.verify(noname.string())) {
	      fs::path newname(path);
	      newname /= boost::lexical_cast<string>(number) + ".doc";
	      rename(noname, newname);
	      fun(number, newname.string());
	      number++;
	  } else {
	      remove(noname);
	  }
      }
      t.expires_from_now(boost::posix_time::seconds(1));
  }
}
