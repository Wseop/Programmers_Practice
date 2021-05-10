// https://programmers.co.kr/learn/courses/30/lessons/42893?language=cpp

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

const string URL_PARSE = "<meta property=\"og:url\" content=\"https://";
const string BODY_PARSE = "<body>";
const string LINK_PARSE = "<a href=\"https://";

void ToLower(string& str) {
    int diff = 'a' - 'A';

    for (int i = 0; i < str.size(); i++) {
        if ((str[i] >= 'A') && (str[i] <= 'Z')) {
            str[i] += diff;
        }
    }
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    double max_point = 0;
    vector<string> urls;
    vector<vector<string>> links;
    map<string, double> base_points;
    map<string, double> link_points;
    map<string, double> match_points;

    ToLower(word);
    for (string page : pages) {
        string url;
        double base_point = 0;

        // url parsing
        ToLower(page);
        size_t url_index = page.find(URL_PARSE);
        url_index += URL_PARSE.size();
        while (page[url_index] != '\"') {
            url += page[url_index++];
        }
        urls.push_back(url);

        // 기본 점수 parsing
        size_t pos = page.find(BODY_PARSE);
        pos += BODY_PARSE.size();
        while (true) {
            pos = page.find(word, pos + 1);
            if (pos == string::npos) break;
            if (page[pos - 1] >= 'a' && page[pos - 1] <= 'z') continue;
            if (page[pos + word.size()] >= 'a' && page[pos + word.size()] <= 'z') continue;
            base_point++;
        }
        base_points.insert({url, base_point});

        // 링크 parsing
        vector<string> link_urls;
        size_t link_index = page.find(LINK_PARSE);
        while (link_index != string::npos) {
            string link_url;

            link_index += LINK_PARSE.size();
            while (page[link_index] != '\"') {
                link_url += page[link_index++];
            }
            link_urls.push_back(link_url);
            link_index = page.find(LINK_PARSE, link_index);
        }
        links.push_back(link_urls);
        link_points.insert({url, base_point / link_urls.size()});
    }
    // 매칭 점수 계산
    for (int i = 0; i < urls.size(); i++) {
        string url = urls[i];
        vector<string> link_urls = links[i];

        // 기본 점수
        match_points[url] += base_points[url];
        // 링크 점수
        for (string link : link_urls) {
            if (base_points[link] != 0) {
                match_points[link] += link_points[url];
            }
        }
    }
    for (int i = 0; i < urls.size(); i++) {
        string url = urls[i];

        if (max_point < match_points[url]) {
            max_point = match_points[url];
            answer = i;
        }
    }

    return answer;
}