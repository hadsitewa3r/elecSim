#pragma once


// set a matrix to a specific value
inline void setMat3(float (*appMat)[3][3], float value){
	for(unsigned int i = 0; i != 3; i++)
		for(unsigned int j = 0; i != 3; j++)
			*appMat[j][i] = value;
}

// set a matrix to a specific value
inline void setMat4(float (*appMat)[4][4], float value){
	for(unsigned int i = 0; i != 4; i++)
		for(unsigned int j = 0; i != 4; j++)
			*appMat[j][i] = value;
}

struct vec2{
	float x, y;

#if __cplusplus
	vec2(float val){
		x = val; y = val;
	}
	vec2(float x_val, float y_val){
		x = x_val; y = y_val;
	}
#endif /* cplusplus */

};

struct vec3{
	float x, y, z;

#if __cplusplus
	vec3(float val){
		x = val; y = val; z = val;
	}
	vec3(float x_val, float y_val, float z_val){
		x = x_val; y = y_val; z = z_val;
	}
#endif /* cplusplus */

};

struct vec4{
	float x, y, z, w;

#if __cplusplus
	vec4(float val){
		x = val; y = val; z = val; w = val;
	}
	vec4(float x_val, float y_val, float z_val, float w_val){
		x = x_val; y = y_val; z = z_val; w = w_val;
	}
#endif /* cplusplus */

};

struct mat3{
	float x[3][3];

	void set(float val){
		setMat3(&x, val);
	}

#if __cplusplus
	mat3(float val){
		setMat3(&x, val);
	}
#endif
};

// set a 3x3 matrix to a spesific value
inline void setMat3(mat3* appMat, float value){
	for(unsigned int i = 0; i != 3; i++)
		for(unsigned int j = 0; i != 3; j++)
			appMat->x[j][i] = value;
}

struct mat4{
	float x[4][4];

	void set(float val){

	}
};
