#include "FaceInfo.h"
#include "face.pb.h"

FaceInfo::FaceInfo() {
    this->direction = DIRECTION::IN;
    this->uuid = QUuid::createUuid();
}

void
FaceInfo::addFace(const QByteArray &face) {
    this->faces.insert(face);
}

void
FaceInfo::setDirection(const DIRECTION &_direction) {
    this->direction = _direction;
}

QUuid
FaceInfo::getUuid() {
    return this->uuid;
}

QByteArray
FaceInfo::getSerializedData() {
    return this->serializedData;
}

void FaceInfo::serialize() {
    Data *data = new Data();
    data->mutable_person()->set_uuid(this->uuid.toByteArray().data());
    data->mutable_person()->set_direction(static_cast< Direction > ( this->direction ));
    int it = 0;
    for (QByteArray face: this->faces) {
        ++it;
        data->mutable_person()->mutable_faces(it)->set_face_data(face.data());
        data->mutable_person()->mutable_faces(it)->set_num(it);
    }
    this->serializedData = data->SerializeAsString().data();
}


