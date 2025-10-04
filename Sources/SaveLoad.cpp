#include "TasksWidget.h"

void TasksWidget::saveList() {
    QSettings settings("Valeriy1729", "TODOlist");
    settings.beginWriteArray("Tasks");

    for (int i = 0; i < LINES_COUNT; i++) {
        settings.setArrayIndex(i);
        settings.setValue("desc", LArray[i]->getText());
        settings.setValue("completed", LArray[i]->getChecked());
        settings.setValue("enabled", LArray[i]->getEnabled());
    }

    settings.setValue("currentline", currentLine);

    settings.endArray();
}

void TasksWidget::loadFromSettings() {
    QSettings settings("Valeriy1729", "TODOlist");
    int size = settings.beginReadArray("Tasks");
    
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        QString desc = settings.value("desc").toString();
        bool completed = settings.value("completed").toBool();
        bool enabled = settings.value("enabled").toBool();
	LArray[i]->setText(desc);
	LArray[i]->setCheckBox(completed);
	LArray[i]->setEnable(enabled);
    }

    currentLine = settings.value("currentline").toInt();

    settings.endArray();
}
