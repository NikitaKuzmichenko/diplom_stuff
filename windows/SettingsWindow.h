#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>

#include <settings/SettingsManager.h>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

    SettingsManager *getManager();
    void setManager(SettingsManager *value);


    QMainWindow *getStartWindow();
    void setStartWindow(QMainWindow *value);

private slots:

    void on_backButton_clicked();
    void on_saveButton_clicked();
    void on_resetButton_clicked();

private:
    QMainWindow * startWindow;

    QStringList colors = {"White","Black", "Red", "Green", "Blue", "Cyan", "Yellow"};
    SettingsManager *manager;

    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
