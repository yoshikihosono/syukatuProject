#pragma once
#include <list>
class GameObject;

class SceneBase {
public:
	SceneBase();
	virtual ~SceneBase();

	virtual void Update();
	virtual void Draw();

	/// <summary>
	/// GameObject�𐶐�����
	/// �����Ő�������ƁAUpdate,Draw���Ă΂��悤�ɂȂ�
	/// </summary>
	template <class C>
	C* CreateGameObject() {
		C* obj = new C(this);
		NODE node;
		node.object = obj;
		m_objects.emplace_back(node);
		m_needSort = true;
		return obj;
	};

	/// <summary>
	/// �N���X����v����GameObject���擾����
	/// </summary>
	/// <returns>GameObject�̃C���X�^���X</returns>
	template<class C>
	C* FindGameObject() const {
		for (auto& m : m_objects) {
			C* obj = dynamic_cast<C*>(m.object);
			if (obj != nullptr)
				return obj;
		}
		return nullptr;
	}

	/// <summary>
	/// �N���X����v����GameObject��S�Ď擾����
	/// </summary>
	/// <returns>GameObject�̃C���X�^���X</returns>
	template<class C>
	std::list<C*> FindGameObjects() const {
		std::list<C*> list;
		for (auto& m : m_objects) {
			C* obj = dynamic_cast<C*>(m.object);
			if (obj != nullptr)
				list.emplace_back(obj);
		}
		return list;
	}

	/// <summary>
	/// �`��̃v���C�I���e�B��ݒ肷��
	/// ���l�����Ȃ����ɕ`�悳���̂ŁA�Q�c�ł͉��ɕ\�������
	/// �Q�c�Ŏ�O�ɕ\�����������A�R�c�Ō�ɕ`�悵�������́A�l����������
	/// �v���C�I���e�B���������̂̏��Ԃ͕ۏ؂���Ȃ�
	/// �v���C�I���e�B�̃f�t�H���g��100�ł�
	/// </summary>
	/// <param name="obj">�v���C�I���e�B��ݒ肷��I�u�W�F�N�g</param>
	/// <param name="order">�`��v���C�I���e�B</param>
	void SetDrawOrder(GameObject* _obj, int _order);

	/// <summary>
	/// GameObject���폜����
	/// </summary>
	/// <param name="obj">GameObject�̃C���X�^���X</param>
	void DeleteGameObject(GameObject* obj);

	/// <summary>
	/// �S�Ă�GameObject���폜����
	/// </summary>
	void DeleteAllGameObject();

	/// <summary>
	/// ���ׂĂ�GameObject���擾����
	/// </summary>
	/// <returns>���ׂĂ�GameObject�̃��X�g</returns>
	std::list<GameObject*> GetAllObjects() const;

private:
	struct NODE {
		int order;
		bool initialized;
		GameObject* object;
		NODE() : order(100), object(nullptr), initialized(false) {}
	};
	std::list<NODE> m_objects;     // �����ŊǗ����Ă���GameObject���X�g
	std::list<NODE> m_drawObjects; // �`��p��GameObject���X�g
	bool m_needSort;

	void DeleteFromDrawObjects(GameObject* obj);
	static bool Comp(const NODE& o1, const NODE& o2);
};
