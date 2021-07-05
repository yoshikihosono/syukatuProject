#pragma once
#include <DxLib.h>
#include <string>
#include "sceneBase.h"

class GameObject {
public:
	GameObject() : m_pScene(nullptr), m_pParent(nullptr), m_destroy(false), m_tag("") {}
	GameObject(SceneBase* scene) : m_pScene(scene), m_pParent(nullptr), m_destroy(false), m_tag("") {}
	GameObject(GameObject* object) : m_pScene(nullptr), m_pParent(object), m_destroy(false), m_tag("") {}
	GameObject(SceneBase* scene, GameObject* object) : m_pScene(scene), m_pParent(object), m_destroy(false), m_tag("") {}
	virtual ~GameObject() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void Draw() {}

	/// <summary>
	/// �����̃C���X�^���X���폜���鎞�ɌĂяo��
	/// �����Update�̑O�ɍ폜�����
	/// </summary>
	void DestroyMe() { m_destroy = true; }

	/// <summary>
	/// �C���X�^���X���폜�v������Ă��邩�𒲂ׂ�
	/// ��ɁASceneManager�Ń`�F�b�N���Ă���
	/// </summary>
	/// <returns></returns>
	bool IsDestroy() const { return m_destroy; }

	/// <summary>
	/// �^�O������
	/// �^�O�͂P�����t���邱�Ƃ��ł��܂�
	/// </summary>
	/// <param name="_tag">�^�O</param>
	void SetTag(std::string _tag) { m_tag = _tag; }

	/// <summary>
	/// �w�肳�ꂽ�^�O�Ɠ�������Ԃ�
	/// </summary>
	/// <param name="_tag">�^�O</param>
	/// <returns>�����ł����true</returns>
	bool IsTag(std::string _tag) const { return m_tag == _tag; }

	/// <summary>
	/// �^�O���擾����
	/// </summary>
	/// <returns>�ݒ肳��Ă���^�O</returns>
	const std::string& GetTag() const { return m_tag; }

	/// <summary>
	/// ��������V�[����Ԃ�
	/// </summary>
	/// <returns>��������V�[���̃|�C���^�[</returns>
	SceneBase* GetScene() const { return m_pScene; }

	/// <summary>
	/// �V�[���̃|�C���^�[��ۑ�����
	/// </summary>
	/// <returns>��������V�[���̃|�C���^�[</returns>
	void SetScene(SceneBase* _scene) { m_pScene = _scene; }

	/// <summary>
	/// �e�̃I�u�W�F�N�g��Ԃ�
	/// </summary>
	/// <returns>�e�I�u�W�F�N�g�̃|�C���^�[</returns>
	GameObject* GetParent() const { return m_pParent; }

	/// <summary>
	/// �e�̃I�u�W�F�N�g��Ԃ�
	/// </summary>
	/// <returns>�e�I�u�W�F�N�g�̃|�C���^�[</returns>
	void SetParent(GameObject* _parent) { m_pParent = _parent; }
private:
	SceneBase* m_pScene; // ��������V�[��
	GameObject* m_pParent; // �e�̃I�u�W�F�N�g
	bool m_destroy;        // �������폜���邩�ۂ�
	std::string m_tag;     // �^�O
};
