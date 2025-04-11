//
// Created by grave on 2025-04-06.
//

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

class Serializable {
public:
    virtual ~Serializable() = default;

    virtual void serialize(std::ostream& out) const = 0;
    virtual void deserialize(std::istream& in) = 0;
};

#endif //SERIALIZABLE_H
