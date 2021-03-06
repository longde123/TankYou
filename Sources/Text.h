#pragma once

#include <Kore/Graphics/Graphics.h>
#include "Kravur.h"

class Text {
private:
	Kore::mat4 projectionMatrix;
	Kore::ConstantLocation projectionLocation;
	Kore::TextureUnit textureLocation;
	int bufferIndex;
	Kore::VertexBuffer* rectVertexBuffer;
	float* rectVertices;
	Kore::IndexBuffer* indexBuffer;
	Kore::Texture* lastTexture;
	int fontSize;
	bool bilinear;
	Kore::Program* program;
public:
	Kravur* font;
	Text();
	void setProjection(int width, int height);
private:
	void initBuffers();
	void setRectVertices(float bottomleftx, float bottomlefty, float topleftx, float toplefty,
		float toprightx, float toprighty, float bottomrightx, float bottomrighty);
	void setRectTexCoords(float left, float top, float right, float bottom);
	void setRectColors(float opacity, int color);
	void drawBuffer();
public:
	void setBilinearFilter(bool bilinear);
	void setFont(Kravur* font);
	void start();
	void drawString(const char* text, int color, float x, float y, const Kore::mat3& transformation);
	void end();
};
