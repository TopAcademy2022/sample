#include "dialog-ai.h"
#include "ui_dialog-ai.h"

DialogAI::DialogAI(void (*ClosedWindowFunction)(char* text), QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAI)
{
    ui->setupUi(this);
    this->ClosedWindow = ClosedWindowFunction;

    connect(this, &this->finished, this, [this](){
        QString text = ui->textEdit->toPlainText();
        this->_text = new char[text.length() + 1];

        for(int i = 0; i < text.length(); i++)
        {
            this->_text[i] = static_cast<char>(text[i].unicode());;
        }

        this->_text[text.length()] = '\0';
        this->ClosedWindow(this->_text);
    });
}

DialogAI::~DialogAI()
{
    delete ui;
}
