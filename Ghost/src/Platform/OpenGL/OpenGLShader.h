#pragma once

#include "Ghost/Renderer/Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// TODO: REMOVE!
typedef unsigned int GLenum;

namespace Ghost {
	class OpenGLShader : public Shader {
	public:
		OpenGLShader();
		virtual ~OpenGLShader();

		virtual bool Compile(const std::string& filepath) override;
		virtual bool Compile(const std::string& name, const std::string& source, const ShaderType type) override;
		virtual bool Link() override;

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const std::string& GetName() const override { return m_Name; }

		void UploadUniformInt(const std::string& name, int value);

		void UploadUniformFloat(const std::string& name, float value);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& values);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& values);
		void UploadUniformFloat4(const std::string& name, const glm::vec4& values);

		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);
		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);

	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);

	private:
		uint32_t m_RendererID;
		std::unordered_map<ShaderType, uint32_t> m_ShaderIDMap;
		std::string m_Name;
	};
}