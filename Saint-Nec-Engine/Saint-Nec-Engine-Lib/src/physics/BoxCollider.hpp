#pragma once
/**
 * @file BoxCollider.hpp
 * @brief Box to detect collision.
 * @author Abdeljalil ZOGHLAMI, Antonin DEVIDAL.
 * @date november 6rd 2023.
 *
 */

#include "architecture/Component.hpp"
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

namespace sne
{

    namespace saintNecPhysics
    {
        /**
         * @class BoxCollider
         * @brief BoxCollider physics component
         */
        class BoxCollider : public sne::Component
        {
        private:
            glm::vec3 _points[8];         // TO UPDATE
            glm::vec3 _rotation{0, 0, 0}; // Radian
            glm::vec3 _center;

        public:
            /**
             * @brief Construct a new Box Collider object
             *
             * @param center
             * @param width (X axis)
             * @param depth (Y axis)
             * @param height (Z axis)
             */
            BoxCollider(const glm::vec3 center, double width, double depth, double height);

            /**
             * @brief Destroy the Box Collider object
             *
             */
            ~BoxCollider() = default;

            /**
             * @brief access to point number i
             *
             * @param i
             * @return const glm::vec3&
             */
            const glm::vec3 &operator[](int i) const;

            /**
             * @brief tell if this object contains a point approximatively close to p
             *
             * @param p point to search
             * @param eps approximation, sphere when we can look for this point
             * @return true
             * @return false
             */
            bool hasPoint(const glm::vec3 &p, float eps = 0) const;

            /**
             * @brief Get the Nb Points object
             *
             * @return int
             */
            int getNbPoints() const;

            /**
             * @brief Set the Rotation object and update points
             *
             * @param rotation
             */
            void setRotation(const glm::vec3 rotation);

            /**
             * @brief Get the Rotation object
             *
             * @return const glm::vec3
             */
            const glm::vec3 getRotation() const;

            /**
             * @brief Get the relative Axis of the object
             *
             * @return std::vector<glm::vec3>
             */
            std::vector<glm::vec3> getAxis() const;
        };

        std::ostream &operator<<(std::ostream &oss, const BoxCollider &b);
    }
}