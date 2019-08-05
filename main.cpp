#include <string>
#include <iostream>
#include <sstream>
#include "curl-7.65.3/include/curl/curl.h"

using namespace std;

void doSearch(string title)
{
    CURL *curl;
    CURLcode res;
    string url = "http://www.omdbapi.com/?t=" + title;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }

}

void printOptions()
{
    cout << "Lista de opções da aplicação" << endl;
    cout << "-h ou --help: imprime a lista de opções da aplicação" << endl;
    cout << "-s ou --search: busca pelo título da media" << endl;
    cout << "-t ou --type: retorna o tipo media selecionado" << endl;
}

void returnType()
{
    // Não entendi o -t
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        string arg = argv[1];
        if (arg.compare("-h") == 0 || arg.compare("--help") == 0)
            printOptions();
        else if (arg.compare("-s") == 0 || arg.compare("--search") == 0)
        {
            string title = "";
            for (int i = 2; i < argc; i++) {
                title = title + "+" + argv[i];
            }

            doSearch(title);
        }
        else if (arg.compare("-t") == 0 || arg.compare("--type") == 0)
            returnType();
    }
    return 0;
}

