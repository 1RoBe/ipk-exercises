#ifndef IPK_HTTP_REQUEST_H
#define IPK_HTTP_REQUEST_H

#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>

#include <curl/curl.h>

namespace ipk::http
{
static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                            void *userp)
{
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

// XXX: add support for writing to file
class Request
{
public:
  Request()
  {
    hnd = curl_easy_init();

    curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
    curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
    //curl_easy_setopt(hnd, CURLOPT_USERAGENT, "curl/7.66.0");
    curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
    curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
    curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
    curl_easy_setopt(hnd, CURLOPT_FOLLOWLOCATION, 1L);
  }

  ~Request()
  {
    curl_easy_cleanup(hnd);
    hnd = nullptr;

    if (list)
    {
      curl_slist_free_all(list);
    }
  }

  void perform(const std::string &uri, const short port = 80)
  {
    curl_easy_setopt(hnd, CURLOPT_URL, uri.c_str());
    curl_easy_setopt(hnd, CURLOPT_PORT, port);

    // set HTTP headers for GET request
    if (list)
    {
      curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, list);
    }

    // set callback
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &buf);

    ret = curl_easy_perform(hnd);
    if (ret != CURLE_OK)
    {
      std::fprintf(stderr, "curl_easy_perform() failed: %s\n",
                   curl_easy_strerror(ret));
    }
  }

  const std::string result()
  {
    return buf;
  }

  void headers(std::vector<std::string> v)
  {
    if (v.size() == 0)
    {
      throw std::invalid_argument("must specify at least one HTTP header");
    }
    for (auto &s : v)
    {
      list = curl_slist_append(list, s.c_str());
    }
  }

private:
  CURL *hnd;
  CURLcode ret;

  std::string buf{};
  struct curl_slist *list = nullptr;
};
} // namespace ipk::http
#endif /* REQUEST_H */