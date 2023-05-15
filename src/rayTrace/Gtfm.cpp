#include "Gtfm.h"

SDLRT::GTform::GTform() : m_fwdtfm(glm::dmat4(1.0)), m_bcktfm(glm::dmat4(1.0)){

}

SDLRT::GTform::GTform(const glm::dmat4& fwd, const glm::dmat4& bck) : m_fwdtfm(fwd), m_bcktfm(bck) {

}

void SDLRT::GTform::SetTransform(const glm::dvec3& translation, const glm::dvec3& rotation,const glm::dvec3& scale) {
    glm::dmat4 transformMatrix; // Initialize as an identity matrix

    // Set the translation component.
    transformMatrix = glm::translate(transformMatrix, translation);
    // Apply scaling.
    transformMatrix = glm::scale(transformMatrix, scale);

#ifdef ZYX
    // Apply rotation in Z, Y, and X order.
    transformMatrix = glm::rotate(transformMatrix, rotation[2], { 0.0f, 0.0f, 1.0f });
    transformMatrix = glm::rotate(transformMatrix, rotation[1], { 0.0f, 1.0f, 0.0f });
    transformMatrix = glm::rotate(transformMatrix, rotation[0], { 1.0f, 0.0f, 0.0f });
#else
    // Apply rotation in X, Y, and Z order.
    transformMatrix = glm::rotate(transformMatrix, rotation[0], { 1.0f, 0.0f, 0.0f });
    transformMatrix = glm::rotate(transformMatrix, rotation[1], { 0.0f, 1.0f, 0.0f });
    transformMatrix = glm::rotate(transformMatrix, rotation[2], { 0.0f, 0.0f, 1.0f });
#endif // ZYX


    // Assign the final transform matrix.
    m_fwdtfm = transformMatrix;

    // Compute the inverse transform.
    m_bcktfm = glm::inverse(transformMatrix);
}

glm::dmat4 SDLRT::GTform::GetForward() const {
    return m_fwdtfm;
}

glm::dmat4 SDLRT::GTform::GetBackward() const {
    return m_bcktfm;
}

SDLRT::Ray SDLRT::GTform::Apply(const Ray& inputRay, bool dirFlag){
    Ray outputRay;
    if (dirFlag) {
        outputRay.m_point1 = this->Apply(inputRay.m_point1, dirFlag);
        outputRay.m_point2 = this->Apply(inputRay.m_point2, dirFlag);
        outputRay.m_lab = outputRay.m_point2 - outputRay.m_point1;

    } else {
        outputRay.m_point1 = this->Apply(inputRay.m_point1, dirFlag);
        outputRay.m_point2 = this->Apply(inputRay.m_point2, dirFlag);
        outputRay.m_lab = outputRay.m_point2 - outputRay.m_point1;
    }
    return outputRay;
}

glm::dvec3 SDLRT::GTform::Apply(const glm::dvec3& inputVector, bool dirFlag) {
    glm::dvec4 tempVector{ inputVector, 1.0 };
    glm::dvec4 resoult{};
    if (dirFlag) {
        resoult = m_fwdtfm * tempVector;
    } else {
        resoult = m_bcktfm * tempVector;
    }
    return glm::dvec3(resoult);
}


SDLRT::GTform SDLRT::operator*(const GTform& lhs, const GTform& rhs) {
    glm::dmat4 fwdRes = lhs.m_fwdtfm * rhs.m_fwdtfm;
    glm::dmat4 bckRes = glm::inverse(fwdRes);
    return GTform(fwdRes, bckRes);
}

SDLRT::GTform& SDLRT::GTform::operator=(const GTform& rhs) {
    if (this == &rhs) {
        return *this;
    }

    m_fwdtfm = rhs.m_fwdtfm;
    m_bcktfm = rhs.m_bcktfm;

    return *this;
}

void SDLRT::GTform::PrintMatrix(bool dirFlag){
    if (dirFlag) {
        Print(m_fwdtfm);
    } else {
        Print(m_bcktfm);
    }
}

void SDLRT::GTform::PrintVector(const glm::dvec3& vector){
    PRINT(12, "Vector: " << glm::to_string(vector));
}

void SDLRT::GTform::Print(const glm::dmat4& matrix){
    PRINT(12, glm::to_string(matrix));
}
