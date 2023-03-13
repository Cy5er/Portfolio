#include "transcript.hpp"

TranscriptRegistry::TranscriptRegistry(){}

void TranscriptRegistry::Add(const Transcript& transcript){
    registry_.push_back(transcript);
}

bool TranscriptRegistry::isIn(const std::string& std_id) const{
    for (auto i:registry_){
        if(std_id == i.student_id){
            return true;
        }
        else return false;
    }
    return false;
}

void TranscriptRegistry::RemoveById(const std::string& std_id){
    auto it = std::remove_if(registry_.begin(), registry_.end(), [std_id](Transcript find){return std_id == find.student_id;});
    registry_.erase(it, registry_.end());
}
std::vector<Transcript>::const_iterator TranscriptRegistry::FindTranscript(const std::string& std_id)const {
    std::vector<Transcript>::const_iterator iter = registry_.cbegin();
    for (auto i:registry_){
        if(i.student_id != std_id){
            iter += 1;
        }
        else return iter;
    }
    return iter;
}

 std::vector<std::pair<std::__cxx11::basic_string<char>, long unsigned int>> TranscriptRegistry::FindCourseResults(const std::string& course_name)const{
    std::vector<std::pair<std::__cxx11::basic_string<char>, long unsigned int>> ans;
    for(auto i:this->registry_){
        std::cout<< i.student_id << std::endl;
        std::cout<< course_name << std::endl;
        

        //auto it = std::find_if(i.grades.begin(), i.grades.end(), [course_name](const std::string& name){return course_name == name;});
        auto a = std::make_pair(i.student_id,grr(course_name,i.grades));
        std::cout << a.first << ","<<a.second << std::endl;
        //ans.push_back(std::make_pair(i.student_id,grr(course_name,i.grades)));
        if(TranscriptRegistry::in(course_name,i.grades)){
            ans.insert(ans.end(),a);
        }
        
    }
    return ans;
}

long unsigned int TranscriptRegistry::grr(const std::string& course_name, std::list<std::pair<std::string, long unsigned int>> gr)const {
    for (auto i:gr){
        if(course_name == std::get<std::string>(i)){
            std::cout<< "Found course" << std::get<long unsigned int>(i) << std::endl;
            return std::get<long unsigned int>(i);
        }
    }
    return 0;
}

bool TranscriptRegistry::in(const std::string& course_name, std::list<std::pair<std::string, long unsigned int>> gr) const{
    for (auto i:gr){
        if(course_name == std::get<std::string>(i)){
            std::cout<< "Found course" << std::get<long unsigned int>(i) << std::endl;
            return true;
        }
    }
    return false;
}

const std::vector<Transcript>& TranscriptRegistry::GetTranscripts()const{
    return test;
}