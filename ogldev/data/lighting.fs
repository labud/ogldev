#version 330
                                      
uniform sampler2D gSampler;                      

struct DirectionalLight                                                             
{                                                                                   
    vec3 Color;                                                                     
    float AmbientIntensity;                                                         
    float DiffuseIntensity;                                                         
    vec3 Direction;                                                                 
};      
                                                              
uniform DirectionalLight gDirectionalLight;                                
uniform vec3 gEyeWorldPos;                                                          
uniform float gMatSpecularIntensity;                                                
uniform float gSpecularPower;                                                       


struct PixelInputType{
	vec2 TexCoord0;
	vec3 Normal0;
	vec3 WorldPos0;
};                                 
						
in vec2 TexCoord0;
in vec3 Normal0;                                                           
in vec3 WorldPos0;                                                                          

PixelInputType getPixelInputType()
{
	PixelInputType tmp;
	tmp.TexCoord0 = TexCoord0;
	tmp.Normal0 = Normal0;
	tmp.WorldPos0 = WorldPos0;
	return tmp;
}
                                                                                 
out vec4 FragColor;      
            
struct PixelOutputType{
	vec4 FragColor;
};

void setPixelOutputType(PixelOutputType tmp)
{
	FragColor = tmp.FragColor;
}

void main()                                                                         
{   
	PixelInputType input = getPixelInputType();
	PixelOutputType output;
	
    vec4 AmbientColor = vec4(gDirectionalLight.Color, 1.0f) * gDirectionalLight.AmbientIntensity;
    vec3 LightDirection = -gDirectionalLight.Direction;                          
    vec3 Normal = normalize(input.Normal0);                                                             
                                                                                    
    float DiffuseFactor = dot(Normal, LightDirection);    
                                                                 
    vec4 DiffuseColor  = vec4(0, 0, 0, 0);                                          
    vec4 SpecularColor = vec4(0, 0, 0, 0);

    if (DiffuseFactor > 0) {                                                        
        DiffuseColor = vec4(gDirectionalLight.Color * gDirectionalLight.DiffuseIntensity * DiffuseFactor, 1.0f);
                                                                                    
        vec3 VertexToEye = normalize(gEyeWorldPos - input.WorldPos0);                     
        vec3 LightReflect = normalize(reflect(gDirectionalLight.Direction, Normal));
        float SpecularFactor = dot(VertexToEye, LightReflect);                      
        if (SpecularFactor > 0) {                                                   
            SpecularFactor = pow(SpecularFactor, gSpecularPower);
            SpecularColor = vec4(gDirectionalLight.Color * gMatSpecularIntensity * SpecularFactor, 1.0f);
        }                                                                           
    }             
	
    output.FragColor = texture2D(gSampler, input.TexCoord0.xy) *                      
                (AmbientColor + DiffuseColor + SpecularColor);    
	setPixelOutputType(output);
}
