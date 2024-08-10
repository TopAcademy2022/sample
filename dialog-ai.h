#ifndef DIALOGAI_H
#define DIALOGAI_H

#include <QDialog>
#include <QObject>
#include <QCloseEvent>

namespace Ui {
class DialogAI;
}

class DialogAI : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAI(void (*ClosedWindowFunction)(char* text), QWidget *parent = nullptr);
    ~DialogAI();

    void (*ClosedWindow)(char* text);
private:
    Ui::DialogAI *ui;

    char* _text;
};

#endif // DIALOGAI_H
