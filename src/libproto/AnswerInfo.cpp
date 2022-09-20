#include "AnswerInfo.h"
#include "face.pb.h"

AnswerInfo::AnswerInfo() = default;

void
AnswerInfo::setSerializedData(const QByteArray &data) {
    this->serializedData = data;
}

bool
AnswerInfo::isAccess() const {
    return access;
}

QUuid AnswerInfo::getUuid() {
    return this->uuid;
}

void AnswerInfo::parseSerializedData() {
    Data* data = new Data();
    data->ParseFromString(this->serializedData.data());
    if (!data->has_answer()){
        return;
    }
    this->access = data->mutable_answer()->access();
    this->uuid = QUuid( QString::fromStdString( data->mutable_answer()->uuid() ) );
}
