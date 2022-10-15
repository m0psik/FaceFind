#include "FaceFinder.h"
#include "FaceInfo.h"
#include <QByteArray>

int main() {
    while (true) {
        FaceFinder finder;
        std::vector< uchar* > faces = finder.start();
        FaceInfo faceInfo;
        for (auto &face: faces) {
            char* data = reinterpret_cast< char* >(face);
            QByteArray face_data = QByteArray::fromRawData(data, static_cast<int>(strlen(data)));
            faceInfo.addFace(face_data);
        }
        faceInfo.setDirection(DIRECTION::IN);
        faceInfo.serialize();
        QUuid uuid = faceInfo.getUuid();
        QByteArray serializeData = faceInfo.getSerializedData();
    }
    return 0;
}
