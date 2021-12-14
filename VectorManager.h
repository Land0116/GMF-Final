#pragma once
#include <math.h>

class VectorManager
{
public:
	VectorManager(float x, float y) : m_x(x), m_y(y) {}
	float getX() {return m_x;}
	float getY() {return m_y;}
	void setX(float x) {m_x = x;}
	void setY(float y) {m_y = y;}

private:
	float m_x;
	float m_y;

public:
	VectorManager operator+ (const VectorManager& v2) const
	{
		return VectorManager(m_x + v2.m_x, m_y + v2.m_y);
	}

	friend VectorManager& operator+= 
	(VectorManager& v1, const VectorManager v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;
		return v1;
	}

	VectorManager operator* (float scalar)
	{
		return VectorManager(m_x * scalar, m_y *scalar);
	}

	VectorManager& operator *= (float scalar)
	{
		m_x *= scalar;
		m_y *= scalar;
		return *this;
	}

	VectorManager operator- (const VectorManager& v2) const
	{
		return VectorManager(m_x - v2.m_x, m_y - v2.m_y);
	}

	friend VectorManager& operator -=
		(VectorManager v1, const VectorManager& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;
		return v1;
	}

	VectorManager operator/(float scalar)
	{
		return VectorManager(m_x / scalar, m_y / scalar);
	}

	VectorManager operator/=(float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;
		return *this;
	}

	float length()
	{
		return sqrt(m_x * m_x + m_y * m_y);
	}

	void normalize()
	{
		float l = length();
		if (l > 0)
		{
			(*this) *= 1 / l;
		}
	}
};