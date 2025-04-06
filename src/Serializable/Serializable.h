//
// Created by grave on 2025-04-06.
//

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

class Serializable {
public:
    virtual ~Serializable() = default;

    virtual void serialize() const = 0;
    virtual void deserialize() = 0;
};

#endif //SERIALIZABLE_H
