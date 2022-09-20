#ifndef FACEFIND_ANSWERINFO_H
#define FACEFIND_ANSWERINFO_H

#include <QUuid>

class AnswerInfo {
    AnswerInfo();
    void setSerializedData(const QByteArray& data);
    void parseSerializedData();
    bool isAccess() const;
    QUuid getUuid();
private:
    QByteArray serializedData;
    bool access{};
    QUuid uuid;
};

#endif //FACEFIND_ANSWERINFO_H
