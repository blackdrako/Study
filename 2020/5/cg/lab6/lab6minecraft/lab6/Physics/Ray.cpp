#include "Ray.h"

Ray::Ray(float yaw, float pitch, const Vector3& origin) noexcept
 :  m_yaw           (glm::radians(yaw))
 ,  m_pitch         (glm::radians(pitch))
 ,  m_startPoint    (origin)
 ,  m_endPoint      (origin)
 {}

 void Ray::step(float scaler) noexcept
 {
     m_endPoint.x -= std::cos (m_yaw)   * scaler;
     m_endPoint.z -= std::sin (m_yaw)   * scaler;
     m_endPoint.y -= std::tan (m_pitch) * scaler;
 }

 const Vector3& Ray::getEndPoint() const noexcept
 {
     return m_endPoint;
 }

float Ray::getLength() noexcept
{
   return glm::distance(m_startPoint, m_endPoint);
}

