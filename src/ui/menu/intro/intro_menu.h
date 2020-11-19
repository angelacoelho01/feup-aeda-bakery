#ifndef FEUP_AEDA_PROJECT_INTRO_MENU_H
#define FEUP_AEDA_PROJECT_INTRO_MENU_H

#include "ui/ui.h"

class LoginMenu;

class IntroMenu : public UI {
public:
    explicit IntroMenu(Store& s);
    void show() override;
    void importData();
    void exportData();
};


#endif //FEUP_AEDA_PROJECT_INTRO_MENU_H
