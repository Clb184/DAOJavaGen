#include "SourceCreator.hpp"

void CreateEntitySource(const entity_descriptor_t& descriptor) {
	char class_name[512] = "";
	char java_src[512] = "";
	sprintf(class_name, "C%s", descriptor.name.data());
	sprintf(java_src, "models/entities/C%s.java", descriptor.name.data());

	FILE* file = fopen(java_src, "w");
	if (file) {
		fprintf(file, "package %s.models.entities;\n\n", descriptor.package_name.data());
		fprintf(file, "import jakarta.persistence.*;\n\n");
		fprintf(file, "// User imports\n");
		for (auto& i : descriptor.imports) {
			fprintf(file, "import %s;\n", i.data());
		}
		fprintf(file, "\n@Entity\n");
		fprintf(file, "@Table(name = \"%s\")\n", descriptor.table_name.data());
		fprintf(file, "public class %s {\n", class_name);
		fprintf(file, "\t// ID for this entity\n");
		fprintf(file, "\t@Id\n");
		fprintf(file, "\t@GeneratedValue(strategy = GenerationType.IDENTITY)\n");
		fprintf(file, "\tprivate Long m_ID;\n\n");
		for (auto& m : descriptor.members) {
			fprintf(file, "\tprivate %s m_%s;\n", m.member_type.c_str(), m.member_name.c_str());
		}
		fprintf(file, "\n");
		for (auto& m : descriptor.members) {
			fprintf(file, "\tpublic void Set%s(%s %s) {\n", m.member_name.c_str(), m.member_type.c_str(), m.member_name.c_str());
			fprintf(file, "\t\tthis.m_%s = %s;\n", m.member_name.c_str(), m.member_name.c_str());
			fprintf(file, "\t}\n\n");
			fprintf(file, "\tpublic %s Get%s() {\n", m.member_type.c_str(), m.member_name.c_str());
			fprintf(file, "\t\treturn this.m_%s;\n", m.member_name.c_str());
			fprintf(file, "\t}\n\n");
		}
		fprintf(file, "}");
		fclose(file);
	}
	else {
		printf("Something gone wrong while creating source file %s\n", java_src);
	}
}

void CreateControllerSource(const entity_descriptor_t& descriptor) {
	char class_name[512] = "";
	char java_src[512] = "";
	sprintf(class_name, "C%sController", descriptor.name.data());
	sprintf(java_src, "controllers/C%sController.java", descriptor.name.data());

	FILE* file = fopen(java_src, "w");
	if (file) {
		fprintf(file, "package %s.controllers;\n\n", descriptor.package_name.data());
		fprintf(file, "import org.springframework.beans.factory.annotation.Autowired;\n");
		fprintf(file, "import org.springframework.http.HttpStatus;\n");
		fprintf(file, "import org.springframework.web.bind.annotation.*;\n");
		fprintf(file, "import %s.models.entities.C%s;\n", descriptor.package_name.data(), descriptor.name.data());
		fprintf(file, "import %s.services.I%sService;\n\n", descriptor.package_name.data(), descriptor.name.data());
		fprintf(file, "@RestController\n");
		fprintf(file, "@RequestMapping(\"api\")\n");
		fprintf(file, "public class %s {\n", class_name);
		fprintf(file, "\t@Autowired\n");
		fprintf(file, "\tprivate I%sService m_Service;\n", descriptor.name.data());
		fprintf(file, "}");
		fclose(file);
	}
	else {
		printf("Something gone wrong while creating source file %s\n", java_src);
	}
}

void CreateDAOSource(const entity_descriptor_t& descriptor) {
	char class_name[512] = "";
	char java_src[512] = "";
	sprintf(class_name, "I%sDAO", descriptor.name.data());
	sprintf(java_src, "models/dao/I%sDAO.java", descriptor.name.data());

	FILE* file = fopen(java_src, "w");
	if (file) {
		fprintf(file, "package %s.models.dao;\n\n", descriptor.package_name.data());
		fprintf(file, "import org.springframework.data.repository.CrudRepository;\n");
		fprintf(file, "import %s.models.entities.C%s;\n\n", descriptor.package_name.data(), descriptor.name.data());
		fprintf(file, "public interface %s extends CrudRepository<C%s, Long> { }\n", class_name, descriptor.name.data());
		fclose(file);
	}
	else {
		printf("Something gone wrong while creating source file %s\n", java_src);
	}
}


void CreateInterfaceSource(const entity_descriptor_t& descriptor) {
	char class_name[512] = "";
	char java_src[512] = "";
	sprintf(class_name, "I%sService", descriptor.name.data());
	sprintf(java_src, "services/I%sService.java", descriptor.name.data());

	FILE* file = fopen(java_src, "w");
	if (file) {
		fprintf(file, "package %s.services;\n\n", descriptor.package_name.data());
		fprintf(file, "import %s.models.entities.C%s;\n", descriptor.package_name.data(), descriptor.name.data());
		fprintf(file, "import java.util.List;\n\n");
		fprintf(file, "public interface %s {\n", class_name);
		fprintf(file, "\tpublic List<C%s> GetAll();\n", descriptor.name.data());
		fprintf(file, "\tpublic C%s Save(C%s object);\n", descriptor.name.data(), descriptor.name.data());
		fprintf(file, "\tpublic C%s FindByID(Long id);\n", descriptor.name.data());
		fprintf(file, "\tpublic void Delete(C%s object);\n", descriptor.name.data());
		fprintf(file, "}");
		fclose(file);
	}
	else {
		printf("Something gone wrong while creating source file %s\n", java_src);
	}
}

void CreateImplementationSource(const entity_descriptor_t& descriptor) {
	char class_name[512] = "";
	char java_src[512] = "";
	sprintf(class_name, "C%sServiceImpl", descriptor.name.data());
	sprintf(java_src, "services/C%sServiceImpl.java", descriptor.name.data());

	FILE* file = fopen(java_src, "w");
	if (file) {
		fprintf(file, "package %s.services;\n\n", descriptor.package_name.data());
		fprintf(file, "import org.springframework.beans.factory.annotation.Autowired;\n");
		fprintf(file, "import org.springframework.stereotype.Service;\n");
		fprintf(file, "import %s.models.dao.I%sDAO;\n", descriptor.package_name.data(), descriptor.name.data());
		fprintf(file, "import %s.models.entities.C%s;\n", descriptor.package_name.data(), descriptor.name.data());
		fprintf(file, "import java.util.List;\n");
		fprintf(file, "import java.util.ArrayList;\n\n");
		fprintf(file, "@Service\n");
		fprintf(file, "public class %s implements I%sService {\n", class_name, descriptor.name.data());
		fprintf(file, "\t@Autowired\n");
		fprintf(file, "\tprivate I%sDAO m_%sDAO;\n\n", descriptor.name.data(), descriptor.name.data());
		fprintf(file, "\t@Override\n");
		fprintf(file, "\tpublic List<C%s> GetAll() {\n", descriptor.name.data());
		fprintf(file, "\t\tList<C%s> list = new ArrayList<C%s>(); \n", descriptor.name.data(), descriptor.name.data());
		fprintf(file, "\t\tm_%sDAO.findAll().forEach(list::add);\n", descriptor.name.data());
		fprintf(file, "\t\treturn list;\n");
		fprintf(file, "\t}\n\n");
		fprintf(file, "\tpublic C%s Save(C%s object) {\n", descriptor.name.data(), descriptor.name.data());
		fprintf(file, "\t\treturn m_%sDAO.save(object);\n", descriptor.name.data());
		fprintf(file, "\t}\n\n");
		fprintf(file, "\tpublic C%s FindByID(Long id) {\n", descriptor.name.data());
		fprintf(file, "\t\treturn m_%sDAO.findById(id).orElse(null);\n", descriptor.name.data());
		fprintf(file, "\t}\n\n");
		fprintf(file, "\tpublic void Delete(C%s object) {\n", descriptor.name.data());
		fprintf(file, "\t\tm_%sDAO.delete(object);\n", descriptor.name.data());
		fprintf(file, "\t}\n\n");
		fprintf(file, "}");
		fclose(file);
	}
	else {
		printf("Something gone wrong while creating source file %s\n", java_src);
	}
}
