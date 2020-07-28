#pragma once

#include <string>
#include <unordered_map>

namespace Ghost {
	enum class ShaderType {
		None = 0, VertexShader = 1, FragmentShader = 2
	};

	class Shader {
	public:
		virtual ~Shader() = default;

		virtual bool Compile(const std::string& filepath) = 0;
		virtual bool Compile(const std::string& name, const std::string& source, const ShaderType type) = 0;
		virtual bool Link() = 0;

		virtual const std::string& GetName() const = 0;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static Ref<Shader> Create(); // Creates an empty shader
	};

	class ShaderLibrary {
	public:
		void Add(const std::string& name, const Ref<Shader>& shader);
		void Add(const Ref<Shader>& shader);

		Ref<Shader> Load(const std::string& filepath);
		Ref<Shader> Load(const std::string& name, const std::string& filepath);

		Ref<Shader> Get(const std::string& name);

		bool Exists(const std::string& name) const;
	private:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};
}