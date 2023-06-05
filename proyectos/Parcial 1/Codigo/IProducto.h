#pragma once

template<typename T>
class IProducto {
public:
    virtual void setCodigo(T codigo) = 0;
    virtual T getCodigo() const = 0;

    virtual void setNombre(const std::string& nombre) = 0;
    virtual std::string getNombre() const = 0;

    virtual void setPrecio(float precio) = 0;
    virtual float getPrecio() const = 0;
};