#ifndef VARIANT_H
#define VARIANT_H

#include <string>

namespace tiny_au3
{

/* FIXME: Implement copy constructor and operator= for the array variants */

class Variant
{
public:
    virtual void SetValue(const std::string& value) = 0;
    virtual std::string GetString() const = 0;
    virtual int GetInt() const = 0;
    virtual double GetDouble() const = 0;
};

class StringVariant : public Variant
{
public:
    virtual void SetValue(const std::string& value);
    virtual std::string GetString() const;
    virtual int GetInt() const;
    virtual double GetDouble() const;

private:
    std::string value_;
};

class IntVariant : public Variant
{
public:
    virtual void SetValue(const std::string& value);
    virtual std::string GetString() const;
    virtual int GetInt() const;
    virtual double GetDouble() const;

private:
    int value_;
};

class DoubleVariant : public Variant
{
public:
    virtual void SetValue(const std::string& value);
    virtual std::string GetString() const;
    virtual int GetInt() const;
    virtual double GetDouble() const;

private:
    double value_;
};

}

#endif
