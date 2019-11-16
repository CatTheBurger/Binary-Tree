#include "node.h"
#include "tree.h"
#include <QDebug>
#include <QRandomGenerator>
#include <QElapsedTimer>

#define MAX_RAND 256

int randInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

class MyTest
{
public:
    int time1, time2, time3;

    MyTest(int t1, int t2, int t3) {
        time1 = t1;
        time2 = t2;
        time3 = t3;
    }

    void print() {
        qDebug() << "| " << time1 << " | " << time2 << " | " << time3 << " |";
    }
};

int main(int argc, char* argv[])
{
    qDebug() << "Generating Results ...............................";

    QList <MyTest*> results;

    for(int j = 0; j < 2500; j++){
        qDebug() << "[ Test " << j + 1 << " ]";

        Tree tree;

        int tr_len = 10; // 10 is a default value

        if (argc > 1) {
            int len = atoi(argv[1]);
            if (len != 0) tr_len = len;

        }

        for(int i = 0; i < tr_len;i++){
            int val = QRandomGenerator::global()->bounded(MAX_RAND);
            qDebug() << val;
            tree.Add(val);
        }

        int time1,time2,time3;

        QElapsedTimer timer;
        timer.start();
        tree.traversal1(tree.root);
        time1 = timer.nsecsElapsed();
        qDebug() << "Time " << time1;
        timer.restart();
        tree.traversal2(tree.root);
        time2 = timer.nsecsElapsed();
        qDebug() << "Time " << time2;
        timer.restart();
        tree.traversal3(tree.root);
        time3 = timer.nsecsElapsed();
        qDebug() << "Time " << time3;

        results.push_back(new MyTest(time1, time2, time3));

        qDebug() << "";
    }

    qDebug() << "Test Result";
    int t1, t2, t3;

    for(int i = 0;i < results.length();i++){
        t1 += results[i]->time1;
        t2 += results[i]->time2;
        t3 += results[i]->time3;
    }

    t1 /= results.length();
    t2 /= results.length();
    t3 /= results.length();

    qDebug() << "| " << t1 << " | " << t2 << " | " << t3 << " |";

    return 0;
}
