#include <iostream>
#include <queue>

class Job
{
private:
    int id;
    std::string user;
    int pages;

    static int count;

public:
    Job(const std::string& u, int p) : user(u), pages(p), id(++count) {}

    friend std::ostream& operator << (std::ostream& os, const Job& j)
    {
        return (os << "id: " << j.id << ", 사용자: " << j.user << ", 페이지 수: " << j.pages << "장");
    }
};

int Job::count = 0;

template<size_t N>
class Printer
{
private:
    std::queue<Job> jobs;

public:
    bool addNewJob(const Job& job)
    {
        if (jobs.size() == N) {
            std::cout << "인쇄 대기열에 추가: " << job << std::endl;
            return false;
        }
        std::cout << "인쇄 대기열에 추가: " << job << std::endl;
        jobs.push(job);
        return true;
    }

    void startPrinting()
    {
        while (not jobs.empty()) {
            std::cout << "인쇄 중: " << jobs.front() << std::endl;
            jobs.pop();
        }
    }
};

int main()
{
    Printer<5> printer;
    Job j1("광희", 10);
    Job j2("정다", 4);
    Job j3("현수", 5);
    Job j4("유미", 7);
    Job j5("채원", 8);
    Job j6("시원", 10);

    printer.addNewJob(j1);
    printer.addNewJob(j2);
    printer.addNewJob(j3);
    printer.addNewJob(j4);
    printer.addNewJob(j5);
    printer.addNewJob(j6);
    printer.startPrinting();

    printer.addNewJob(j6);
    printer.startPrinting();

    return 0;
}