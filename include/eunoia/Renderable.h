#pragma once
class Renderable{
    public:
        virtual void render() = 0;
        virtual void remove() = 0;
        virtual ~Renderable() = default;
};
