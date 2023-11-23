#include "SphereCollider.hpp"
#include "SAT.hpp"

namespace sne
{

    namespace saintNecPhysics

    {
        SphereCollider::SphereCollider(glm::vec3 center, double radius) : _center(center), _radius(radius)
        {
        }

        const double SphereCollider::getRadius() const
        {
            return _radius;
        }

        bool SphereCollider::collide(const Collider *c) const 
        {
            return c->collide(*this);
        }

        bool SphereCollider::collide(const SphereCollider &s) const
        {
            return hasSATCollision(*this, s); 
            // Used like that because in the futur, template foncteur
        }
        bool SphereCollider::collide(const BoxCollider& b) const 
        {
            return hasSATCollision(*this, b);
        }
    }
}