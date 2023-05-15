#pragma once
#include "headers.h"
#include "Ray.h"

namespace SDLRT {
	class GTform {
	public:
		GTform();
		GTform(const glm::dmat4 &fwd, const glm::dmat4& bck);
		~GTform() = default;
		void SetTransform(const glm::dvec3& translation, const glm::dvec3& rotation, const glm::dvec3& scale);
		glm::dmat4 GetForward() const;
		glm::dmat4 GetBackward() const;
		Ray Apply(const Ray& inputRay, bool dirFlag);
		glm::dvec3 Apply(const glm::dvec3& inputVector, bool dirFlag);

		friend GTform operator* (const GTform& lhs, const GTform& rhs);
		GTform& operator= (const GTform& rhs);
        void PrintMatrix(bool dirFlag);
		// Function to allow printing of vectors.
		static void PrintVector(const glm::dvec3& vector);
	private:
        void Print(const glm::dmat4& matrix);
        glm::dmat4 m_fwdtfm{};
        glm::dmat4 m_bcktfm{};
	};

}