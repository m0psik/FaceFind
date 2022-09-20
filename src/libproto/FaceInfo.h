#ifndef FACEFIND_FACEINFO_H
#define FACEFIND_FACEINFO_H

#include <set>
#include <QUuid>

enum DIRECTION {
    IN  = 0,
    OUT = 1
};

class FaceInfo {
    FaceInfo();

    void addFace(const QByteArray& face);
    void setDirection(const DIRECTION& _direction);
    void serialize();

    QUuid getUuid();
    QByteArray getSerializedData();

private:
    DIRECTION direction;
    std::set< QByteArray > faces;
    QUuid uuid;
    QByteArray serializedData;
};

#endif //FACEFIND_FACEINFO_H
