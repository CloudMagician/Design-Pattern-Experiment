#include <iostream>
#include <string>
#include <queue>

using namespace std;

class ExportDataModel {
private:
    string productId;
    double price;
    double amount;
public:
    string getProductId() {
        return productId;
    }
    void setProductId(string productId) {
        this->productId = productId;
    }
    double getPrice() {
        return price;
    }
    void setPrice(double price) {
        this->price = price;
    }
    double getAmount() {
        return amount;
    }
    void setAmount(double amount) {
        this->amount = amount;
    }
};

class ExportFooterModel {
private:
    string exportUser;
public:
    string getExportUser() {
        return exportUser;
    }
    void setExportUser(string exportUser) {
        this->exportUser = exportUser;
    }
};

class ExportHeaderModel {
private:
    string depId;
    string exportDate;
public:
    string getDepId() {
        return depId;
    }
    void setDepId(string depId) {
        this->depId = depId;
    }
    string getExportDate() {
        return exportDate;
    }
    void setExportDate(string exportDate) {
        this->exportDate = exportDate;
    }
};

class Builder {
public:
    virtual void buildHeader(ExportHeaderModel* ehm){};
    virtual void buildBody(string tblName,queue<ExportDataModel*>*){};
    virtual void buildFooter(ExportFooterModel* efm){};
};

class Director {
private:
    Builder* builder;
public:
    Director(Builder* builder) {
        this->builder = builder;
    }
    virtual void construct(ExportHeaderModel* ehm, string tblName,
                           queue<ExportDataModel*>* queueData,ExportFooterModel* efm) {
        builder->buildHeader(ehm);
        builder->buildBody(tblName,queueData);
        builder->buildFooter(efm);
    }
};

class TxtBuilder : public Builder {
private:
    string buffer;
public:
    void buildBody(string tblName, queue<ExportDataModel*>* queueData) {
        ExportDataModel* temp;
        buffer.append(tblName);
        buffer.append("\n");
        while (!queueData->empty()) {
            temp = queueData->front();
            buffer.append(temp->getProductId());
            buffer.append(",");
            buffer.append(to_string(temp->getPrice()));
            buffer.append(",");
            buffer.append(to_string(temp->getAmount()));
            buffer.append("\n");
            queueData->pop();
        }
    }
    void buildFooter(ExportFooterModel* efm) {
        buffer.append(efm->getExportUser());
    }
    void buildHeader(ExportHeaderModel* ehm) {
        buffer.append(ehm->getDepId());
        buffer.append(",");
        buffer.append(ehm->getExportDate());
        buffer.append("\n");
    }
    string getResult() {
        return buffer;
    }
};

int main(int argc, const char * argv[]) {
    ExportHeaderModel* ehm = new ExportHeaderModel();
    ehm->setDepId("本公司");
    ehm->setExportDate("2010-05-18");
    
    ExportDataModel* edm1 = new ExportDataModel();
    edm1->setProductId("产品001号");
    edm1->setPrice(100);
    edm1->setAmount(80);
    
    ExportDataModel* edm2 = new ExportDataModel();
    edm2->setProductId("产品002号");
    edm2->setPrice(99);
    edm2->setAmount(55);
    
    queue<ExportDataModel*>* queueData = new queue<ExportDataModel*>();
    queueData->push(edm1);
    queueData->push(edm2);
    
    ExportFooterModel* efm = new ExportFooterModel();
    efm->setExportUser("张三");
    
    TxtBuilder* txtBuilder = new TxtBuilder();
    Director* director = new Director(txtBuilder);
    director->construct(ehm,"销售记录表",queueData, efm);
    cout << "输出到文本文件的内容：" << endl << txtBuilder->getResult() << endl;
}
