
#include "ticketmanagesystem.h"

#include <QApplication>
//此处为iof读取文件的路径,未作修改，仅提出函数外方便修改（害怕莫名bug出现）
const string inPath="D:/Code/C++/Project";

int main(int argc, char *argv[]) {
    IOFunc iof;
    std::ofstream ofs("data.bin", std::ios::binary);
    iof.readFlightData(inPath+"/data.dat");
    QApplication a(argc, argv);
    TicketManageSystem w;
    w.show();
    return a.exec();
}

//#include "Console.h"
//
//int main(){
//    Console console;
//    console.run();
//}
