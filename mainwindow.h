#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        MainWindow();

    protected:
        void closeEvent(QCloseEvent *event);

    private slots:
        void newFile();
        void open();
        bool save();
        bool saveAs();
        void find();
        void goToCell();
        void sort();
        void about();
        void openRecentFile();
        void updateStatusBar();
        void spreadsheetModified();

    private:
        void createActions();
        void createMenus();
        void createContextMenu();
        void createToolBars();
        void createStatusBar();
        void readSettings();
        void writeSettings();
        bool okToContinue();
        bool loadFile(const QString &fileName);
        bool saveFile(const QString &fileName);
        void setCurrentFile(const QString &fileName);
        void updateRecentFileActions();
        QString strippedName(const QString &fullFileName);

    private:
        Spreadsheet *spreadsheet;
        FindDialog *findDialog;
        QLabel *locationLabel;
        QLabel *formulaLabel;
        QStringList recentFiles;
        QString curFile;

        enum { MaxRecentFiles = 5 };
        QMenu *fileMenu;
        QMenu *editMenu;
        QMenu *selectSubMenu;
        QMenu *toolsMenu;
        QMenu *optionsMenu;
        QMenu *helpMenu;

        QToolBar *fileToolBar;
        QToolBar *editToolBar;

        QAction *newAction;
        QAction *openAction;
        QAction *saveAction;
        QAction *savesAsAction;
        QAction *exitAction;
        QAction *aboutQtAction;
        QAction *selectAllAction;
        QAction *showGridAction;
        QAction *recentFileActions[MaxRecentFiles];
        QAction *separatorAction;
};

#endif // MAINWINDOW_H
